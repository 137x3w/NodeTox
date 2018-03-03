import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import TextField from 'material-ui/TextField';

const styles = theme => ({});

class StatusMessage extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.handleStatusMessageValueChanged = this.handleStatusMessageValueChanged.bind(this);
  }

  handleStatusMessageValueChanged = function(event) {
    var value = event.target.value;
    this.props.statusMessageCallback(value);
  }

  render() {
    return (
      <ListItem>
        <TextField              
          defaultValue={ this.props.statusMessage }
          onChange={ this.handleStatusMessageValueChanged }
          label="Status message"
          fullWidth
        />
      </ListItem>
    );
  }
}

StatusMessage.propTypes = {
  classes: PropTypes.object.isRequired,
  statusMessage: PropTypes.string,
  statusMessageCallback: PropTypes.func,
};

StatusMessage.defaultProps = {
  statusMessage: "",
  statusMessageCallback: ((newStatusMessage) => {}),
}

export default withStyles(styles)(StatusMessage);