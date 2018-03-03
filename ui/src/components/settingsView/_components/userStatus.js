import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import { FormControl, FormHelperText } from 'material-ui/Form';
import Select from 'material-ui/Select';
import { MenuItem } from 'material-ui/Menu';

const styles = theme => ({});

class UserStatus extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {
      userStatus: props.userStatus,
    }
    this.handleUserStatusChange = this.handleUserStatusChange.bind(this);
  }

  handleUserStatusChange = function(event) {
    var value = event.target.value;
    this.setState({
      userStatus: value,
    });
    this.props.userStatusCallback(value);
  }

  componentWillReceiveProps = function(nextProps) {
    this.setState({
      userStatus: nextProps.userStatus,
    });
  }

  render() {
    return (
      <ListItem>
        <FormControl>
          <Select
            autoWidth
            value={ this.state.userStatus }
            onChange={ this.handleUserStatusChange }
          >
            <MenuItem value={0}>None</MenuItem>
            <MenuItem value={1}>Away</MenuItem>
            <MenuItem value={2}>Busy</MenuItem>
          </Select>
          <FormHelperText>Select connection status</FormHelperText>
        </FormControl>
      </ListItem>
    );
  }
}

UserStatus.propTypes = {
  classes: PropTypes.object.isRequired,
  userStatus: PropTypes.number,
  userStatusCallback: PropTypes.func,
};

UserStatus.defaultProps = {
  userStatus: 0,
  userStatusCallback: ((newStatus) => {}),
}

export default withStyles(styles)(UserStatus);