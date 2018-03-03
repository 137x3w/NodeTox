import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemText, ListItemSecondaryAction } from 'material-ui/List';
import Switch from 'material-ui/Switch';

class Toggle extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      checked: props.checked,
    }
    this.handleToggle = this.handleToggle.bind(this);
  }

  handleToggle = function(event, checked) {
    this.setState({
      checked: checked,
    });
    this.props.toggleCallback(event, checked);
  }

  componentWillReceiveProps = function(nextProps) {
    this.setState({
      checked: nextProps.checked,
    });
  }

  render() {
    return (
      <ListItem>
        <ListItemText primary={ this.props.primaryText }/>
        <ListItemSecondaryAction>
          <Switch
            onChange={ this.handleToggle }
            checked={ this.state.checked }
          />
        </ListItemSecondaryAction>
      </ListItem>
    );
  }
}

Toggle.propTypes = {
  primaryText: PropTypes.string,
  toggleCallback: PropTypes.func,
};

Toggle.defaultProps = {
  primaryText: "Default",
  toggleCallback: ((event, checked) => {}),
}

export default Toggle;