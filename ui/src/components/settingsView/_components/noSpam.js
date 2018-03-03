import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemText } from 'material-ui/List';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';

const styles = theme => ({
  primaryText: {
    flex: 1,
    cursor: 'pointer',
  },
});

class NoSpam extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.handleNoSpamGenerateClick = this.handleNoSpamGenerateClick.bind(this);
  }

  handleNoSpamGenerateClick = function() {
    this.props.noSpamCallback();
  }

  render() {
    return (
      <ListItem>
        <ListItemText 
          disableTypography
          primary={
            <Typography noWrap variant="subheading" className={ this.classes.primaryText }>
              { this.props.noSpam }
            </Typography>
          }
          secondary={
            <Typography noWrap variant="caption">
              Nospam
            </Typography>
          }
        />
        <Button
          onClick={ this.handleNoSpamGenerateClick }
        >
          Generate new
        </Button>
      </ListItem>
    );
  }
}

NoSpam.propTypes = {
  classes: PropTypes.object.isRequired,
  noSpam: PropTypes.number,
  noSpamCallback: PropTypes.func,
};

NoSpam.defaultProps = {
  noSpam: 0,
  noSpamCallback: (() => {})
}

export default withStyles(styles)(NoSpam);